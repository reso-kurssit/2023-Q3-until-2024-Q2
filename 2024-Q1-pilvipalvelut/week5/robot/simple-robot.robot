*** Settings ***
Library           OperatingSystem
Library           String

*** Variables ***
${TESTS_FOLDER}=    ${CURDIR}${/}..${/}tests
${FILE_NAME}      *.*

*** Test Cases ***
Verify Pushed File Contains Words
    ${files}=    List Directory    ${TESTS_FOLDER}
    FOR    ${file}    IN    @{files}
        ${file_contents}=    Get File    ${TESTS_FOLDER}${/}${file}
        Should Contain    ${file_contents}    tää
        Should Contain    ${file_contents}    toi
    END