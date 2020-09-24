### External Module File for Common-Utilities ###
if (COMMON_UTILITIES_INCLUDE_DIR)
    ## In cache already or user-specified ##
    set(COMMON_UTILITIES_FOUND True)

else()
    set(COMMON_UTILITIES_FOUND False)

    if (NOT COMMON_UTILITIES_INCLUDE_DIR)
        find_path(COMMON_UTILITIES_INCLUDE_DIR common-utils
                  PATHS /usr/include/common-utils
                        /usr/include
                        /usr/local/include/common-utils
                        /usr/local/include
                        ~/include/common-utils
                        ~/include)
    endif()

    if (COMMON_UTILITIES_INCLUDE_DIR)
        set(COMMON_UTILITIES_FOUND True)
    endif()
endif()
