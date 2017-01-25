# Python 3.3.3 and 2.7.6
# python helloworld_python.py

from threading import Thread
import thread
import threading

i = 0

def f1():


    global i
    
    for j in range(0, 1000000):
    	lock1.acquire()
    	i = i+1
    	lock1.release()

def f2():

    global i
    
    for j in range(0, 1000000):
    	lock1.acquire()
    	i=i-1
    	lock1.release()


lock1 = threading.Lock()


def main():
    t1 = Thread(target = f1, args = (),)
    t2 = Thread(target = f2, args = (),)

    t1.start()
    t2.start()

    t1.join()
    t2.join()
    print("Python", i)


main()