@echo off
timeout 5


cd C:\Program Files (x86)\Steam\steamapps\common\Arma 3 Tools\AddonBuilder

AddonBuilder.exe "C:\Users\Administrator\Desktop\Arma 3 Files\Altis_Life.Altis" "C:\server\A3Master\mpmissions"

timeout 5

AddonBuilder.exe "C:\Users\Administrator\Desktop\Arma 3 Files\@life_server\addons\life_server" "C:\server\A3Master\@life_server\addons"