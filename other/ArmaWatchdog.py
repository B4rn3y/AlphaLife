import psutil
import subprocess
import time
import os

print(time.strftime("%Y-%m-%d %H:%M:%S", time.gmtime()), "Watchdog started")

backup_interval = 360   # jede halbe stunde
time_counter = 0
max_backups = 96;
path = 'C:\\server\\A3Master\\DB_BACKUPS'

while True:
    server = False

    for p in psutil.process_iter():
        if "arma3server_x64.exe" == p.name():
            server = True

    if not server:
        print(time.strftime("%Y-%m-%d %H:%M:%S", time.gmtime()), "Server is running:", server,"restarting...")
        #print(time.strftime("%Y-%m-%d %H:%M:%S", time.gmtime()), "Beginning packing of PBOs")
        #subprocess.call([r"C:\server\A3Master\Server Scripts\pbo_packer.bat"])
        #print(time.strftime("%Y-%m-%d %H:%M:%S", time.gmtime()), "PBOs packed")
        subprocess.call([r"C:\server\A3Master\Server Scripts\restart_server.bat"])
        time_counter = 0
        subprocess.call([r"C:\server\A3Master\Server Scripts\backup_DB.bat"])
        print("Restart done + DB BACKUP MADE")
        files = []
        # r=root, d=directories, f = files
        for r, d, f in os.walk(path):
            for file in f:
                if '.sql' in file:
                    files.append(os.path.join(r, file))

        if (len(files) > max_backups):
            dif = len(files) - max_backups
            print("Deleting Files:", str(dif))
            for i in range(dif):
                os.remove(files[i])
                print("Deleted: ", str(files[i]))
    time.sleep(5)
    time_counter = time_counter + 1
    if(time_counter >= backup_interval):
        time_counter = 0
        files = []
        # r=root, d=directories, f = files
        for r, d, f in os.walk(path):
            for file in f:
                if '.sql' in file:
                    files.append(os.path.join(r, file))

        if (len(files) > max_backups):
            dif = len(files) - max_backups
            print("Deleting Files: ",str(dif))
            for i in range(dif):
                os.remove(files[i])
                print("Deleted: ",str(files[i]))
        time_counter = 0
        subprocess.call([r"C:\server\A3Master\Server Scripts\backup_DB.bat"])
        print("DB BACKUP MADE")