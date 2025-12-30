@echo off
chcp 65001 >nul

echo Автоматический запуск start.py
echo.

if not exist "start.py" (
    echo Файл start.py не найден!
    pause
    exit /b 1
)

REM Запускаем Python
echo Запускаю start.py...
start "" python start.py

REM Ждем 2 секунды
echo Ожидание 2 секунды перед отправкой 'y'...
timeout /t 2 /nobreak >nul

REM Отправляем 'y' в окно Python
echo Отправляю 'y' в консоль...
powershell -Command "$process = Get-Process | Where-Object { $_.MainWindowTitle -like '*python*' -or $_.MainWindowTitle -like '*start.py*' }; if ($process) { $wshell = New-Object -ComObject wscript.shell; $wshell.AppActivate($process.Id); Start-Sleep -m 500; $wshell.SendKeys('y{ENTER}'); Write-Host '✅ y отправлен' -ForegroundColor Green } else { Write-Host '❌ Окно Python не найдено' -ForegroundColor Red }"

echo.
pause