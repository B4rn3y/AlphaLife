@echo off
timeout 5
::KILL SERVER
taskkill /f /im arma3server_x64.exe
taskkill /f /im arma3server_x64.exe
taskkill /f /im arma3server_x64.exe
taskkill /f /im BEC.exe
taskkill /f /im BEC.exe
taskkill /f /im BEC.exe

timeout 10

 start /min "" "C:\server\A3Master\arma3server_x64.exe" -cfg=basic.cfg -config=server.cfg -bepath=C:\server\A3Master\battleye -profiles=C:\server\A3Master -autoinit "-servermod=@extDB3;@life_server"

timeout 5
cd C:\server\A3Master\BEC
start /min "" "C:\server\A3Master\BEC\Bec.exe"

exit