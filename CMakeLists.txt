cmake_minimum_required(VERSION 3.16.3)

if (APPLE) # macos
    message(STATUS "System: macos")
    add_definitions(-D_FILE_OFFSET_BITS=64 -DWXUSINGDLL -D__WXMAC__ -D__WXOSX__ -D__WXOSX_COCOA__)
elseif(WIN32) # windows
    message(STATUS "System: windows")
else() # unix/linux
    message(STATUS "System: linux")
    add_definitions(-D_FILE_OFFSET_BITS=64 -DWXUSINGDLL -D__WXGTK__)
endif()

project(bitcoin)

add_executable(${PROJECT_NAME}
        src/app.cpp
        src/ui/MainFrameBase.cpp
        src/ui/TxDetailDialogBase.cpp
        src/ui/OptionsDialogBase.cpp
        src/ui/AboutDialogBase.cpp
        src/ui/SendDialogBase.cpp
        src/ui/SendingDialogBase.cpp
        src/ui/YourAddressDialogBase.cpp
        src/ui/AddressBookDialogBase.cpp
        src/ui/ProductsDialogBase.cpp
        src/ui/EditProductDialogBase.cpp
        src/ui/ViewProductDialogBase.cpp
        src/ui/ViewOrderDialogBase.cpp
        src/ui/EditReviewDialogBase.cpp
        src/ui/PokerLobbyDialogBase.cpp
        src/ui/GetTextFromUserDialogBase.cpp
        src/ui/PokerDialogBase.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC
        pthread
        wx_gtk3u_richtext-3.2
        wx_gtk3u_xrc-3.2
        wx_gtk3u_html-3.2
        wx_gtk3u_qa-3.2
        wx_gtk3u_core-3.2
        wx_baseu_xml-3.2
        wx_baseu_net-3.2
        wx_baseu-3.2)