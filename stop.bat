@echo off
echo Останавливаю локальный сервер на порту 8000...

:: Находим и убиваем процесс Python на порту 8000
netstat -ano | findstr :8000 > nul
if %errorlevel% equ 0 (
    for /f "tokens=5" %%a in ('netstat -ano ^| findstr :8000') do (
        echo Найден процесс PID: %%a
        taskkill /F /PID %%a
        echo ✓ Сервер остановлен
    )
) else (
    echo ✓ Сервер не запущен
)

pause