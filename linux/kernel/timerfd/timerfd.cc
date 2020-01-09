#include <sys/epoll.h>
#include <sys/timerfd.h>
#include <strings.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

int main()
{
    int efd = epoll_create(256);
    struct epoll_event ev, events[256];

    int tfd;//timer fd

    if ((tfd = timerfd_create(CLOCK_MONOTONIC, TFD_NONBLOCK)) < 0)
        cout << "timerfd create error" << endl;

    struct itimerspec newValue;
    struct itimerspec oldValue;
    bzero(&newValue, sizeof(newValue));
    bzero(&oldValue, sizeof(oldValue));
    struct timespec ts;
    ts.tv_sec = 5;
    ts.tv_nsec = 0;

    //both interval and value have been set
    newValue.it_value = ts;
    newValue.it_interval = ts;
    if ( timerfd_settime(tfd, 0, &newValue, &oldValue) < 0) {
        cout << "settime error" << strerror(errno) << endl;
    }

    ev.data.fd = tfd;
    ev.events = EPOLLIN | EPOLLET;

    if ( epoll_ctl(efd, EPOLL_CTL_ADD, tfd, &ev) < 0)
        cout << "epoll_ctl error" << endl;

    int num = 0;
    while (1) {
        sleep(10);
        if ((num = epoll_wait(efd, events, 256, 1000)) > 0) {
            //justice
            for (int i = 0; i < num; i++) {
                if (events[i].data.fd == tfd) {
                    uint64_t value;
                    read(tfd, &value, 8);
                    cout << "timeout:" << "value = " << value << endl;
                }
            }
        }
    }
    return 0;
}

// http://blog.chinaunix.net/uid-28541347-id-4273856.html
/*
ET:
 对于读取操作：
(1) 当buffer由不可读状态变为可读的时候，即由空变为不空的时候。
(2) 当有新数据到达时，即buffer中的待读内容变多的时候。

对于写操作：
(1) 当buffer由不可写变为可写的时候，即由满状态变为不满状态的时候。
(2) 当有旧数据被发送走时，即buffer中待写的内容变少得时候。

LT:
对于读操作：
(1) buffer中有数据可读的时候，即buffer不空的时候fd的events的可读为就置1。
对于写操作：
(1) buffer中有空间可写的时候，即buffer不满的时候fd的events的可写位就置1。
*/
