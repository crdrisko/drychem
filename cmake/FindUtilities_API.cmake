if (UTILITIES_API_INCLUDE_DIR)
    ## In cache already or user-specified ##
    set(UTILITIES_API_FOUND TRUE)

else()
    if (NOT UTILITIES_API_INCLUDE_DIR)
        find_path(UTILITIES_API_INCLUDE_DIR utils-api
                  PATHS /usr/include/utils-api
                        /usr/include
                        /usr/local/include/utils-api
                        /usr/local/include
                        ~/include/utils-api
                        ~/include)
    endif()

    if (UTILITIES_API_INCLUDE_DIR)
        set(UTILITIES_API_FOUND TRUE)
endif()
