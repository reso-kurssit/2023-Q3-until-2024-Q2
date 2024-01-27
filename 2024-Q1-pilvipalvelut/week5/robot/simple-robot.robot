*** Test Cases ***
Verify Pushed File In Directory  ../tests
${files}=  List Files In Directory  ../tests
:FOR ${file}  IN  @{files}
\  ${file_contents}=  Get File  ../tests/${file}
\  Should Contain  ${file_contents}  tää
\  Should Contain  ${file_contents}  toi
