# Make appdata optional when installing an application.
if(APPDATA)
    add_custom_target(appdata)
    
    file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/PO_files/")

    add_custom_command(TARGET appdata PRE_BUILD
        # Add an entry per language
        COMMAND msgfmt "${PROJECT_SOURCE_DIR}/other/appdata/PO_files/en.po" -o "${CMAKE_CURRENT_BINARY_DIR}/PO_files/en.mo"

        COMMAND itstool -i "${PROJECT_SOURCE_DIR}/other/appdata/appdata.its" -j "${PROJECT_SOURCE_DIR}/other/appdata/com.github.juliagoda.antimicro.appdata.xml.in" -o "com.github.juliagoda.antimicro.appdata.xml" "${CMAKE_CURRENT_BINARY_DIR}/PO_files/*.mo"
    )

    # Only install an appdata file if the user requested to have one built.
    install(FILES "${CMAKE_CURRENT_BINARY_DIR}/com.github.juliagoda.antimicro.appdata.xml" DESTINATION "${CMAKE_INSTALL_DATAROOTDIR}/metainfo")
endif(APPDATA)
