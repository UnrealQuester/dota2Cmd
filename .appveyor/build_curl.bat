if not exist curl-src (
    call "C:\Program Files\Microsoft SDKs\Windows\v7.1\Bin\SetEnv.cmd" /x64
    cinst -y curl
    curl -L -o curl.zip http://curl.haxx.se/download/curl-%CURL_VERSION%.zip
    7z x curl.zip > NUL
    rename curl-%CURL_VERSION% curl-src
    cd curl-src\winbuild
    nmake /f Makefile.vc mode=static
    cd ..\..
)
