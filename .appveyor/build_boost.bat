dir %BOOST_LIBRARYDIR%
if not exist %BOOST_LIBRARYDIR% (
   cd c:\Libraries\boost
   bootstrap
   .\b2 variant=debug threading=multi runtime-link=shared address-model=%ADDRESS_MODEL%
   cd %APPVEYOR_BUILD_FOLDER%
)
