cmake_minimum_required(VERSION 3.16.3)
add_definitions(-D_FILE_OFFSET_BITS=64 -DWXUSINGDLL -D__WXGTK__)
project(bitcoin)

add_executable(${PROJECT_NAME}
        app.cpp
        ui/CMainFrameBase.cpp
        ui/CTxDetailDialogBase.cpp
        ui/COptionsDialogBase.cpp
        ui/CAboutDialogBase.cpp
        ui/CSendDialogBase.cpp
        ui/CSendingDialogBase.cpp
        ui/CYourAddressDialogBase.cpp
        ui/CAddressBookDialogBase.cpp
        ui/CProductsDialogBase.cpp
        ui/CEditProductDialogBase.cpp
        ui/CViewProductDialogBase.cpp
        ui/CViewOrderDialogBase.cpp
        ui/CEditReviewDialogBase.cpp
        ui/CPokerLobbyDialogBase.cpp
        ui/CGetTextFromUserDialogBase.cpp ui/CPokerDialogBase.cpp)

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