@echo off
timeout 5
cd "C:\Program Files\MariaDB 10.5\bin"

for /f "tokens=2 delims==" %%a in ('wmic OS Get localdatetime /value') do set "dt=%%a"
set "YY=%dt:~2,2%" & set "YYYY=%dt:~0,4%" & set "MM=%dt:~4,2%" & set "DD=%dt:~6,2%"
set "HH=%dt:~8,2%" & set "Min=%dt:~10,2%" & set "Sec=%dt:~12,2%"

set "datestamp=%YYYY%%MM%%DD%" & set "timestamp=%HH%%Min%%Sec%"
set "fullstamp=%YYYY%-%MM%-%DD%_%HH%-%Min%-%Sec%"

set "pfad=C:\server\A3Master\DB_BACKUPS\DB_Backup_%fullstamp%.sql"

start /min "" "mysqldump.exe" --user=root --password=S4NDw!CH25_B4UM2 --host=localhost --port=3306 --result-file="%pfad%" --databases "altislife"



exit