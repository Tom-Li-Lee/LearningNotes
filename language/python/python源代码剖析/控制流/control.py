a = 1
if a > 10 :
    print 'a > 10'
elif a <= -2:
    print 'a <= -2'
elif a != 1:
    print 'a != 1'      
elif a == 1:
    print 'a == 1'
else:
    print 'Unknown a'

lst = [1,2]
for i in lst:
    print i

if 1 in lst:
    print 'Found'
    
i = 0
while i < 10:
    i += 1
    if i > 5:
        continue
    if i == 20:
        break
    print i

try:
    raise Exception( 'i am an exception' )
except Exception, e:
    print e
finally:
    print 'the finally code'    
    

def h():
    1/0

def g():
    h()

def f():
    g()

def f(a, b = 2):
    pass



def Py_Func(value, *lst, **keys):
    pass

Py_Func(-1, 1, 2, a = 3, b = 4)


def get_func():
    value = 'inner'
    def inner_func():
        print value
    return inner_func

show_value = get_func()
show_value()



def should_say(fn):
    def say(*args):
        print 'Say something...'
        fn(*args)
    return say

@should_say
def func(a, b, c):
    print 'in func'
func(1, 2, 3)