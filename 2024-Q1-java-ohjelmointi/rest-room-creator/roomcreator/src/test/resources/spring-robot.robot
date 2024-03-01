*** Settings ***
Library  RequestsLibrary
Library  Collections
Library  OperatingSystem

*** Variables ***
${BASE_URL}   http://localhost:8080
${HEADER}     Content-Type=application/json

*** Test Cases ***
Test Room Creation
    ${startGameRequest}  Start Game Request  5  4  2.57  1300
    Log  ${startGameRequest}
    Check Start Game Request  ${startGameRequest}
    
    ${room}  Get Room
    Check Room Data  ${room}
    
    ${remainingBudget}  Get Budget
    Check Remaining Budget  ${remainingBudget}

Test Material Changes on Walls
    ${wallTypes}  Get Wall Types
    Log  Available Wall Types: ${wallTypes}

    Update Wall  3  WALLPAPER5

    Update Wall  0  WALLPAPER3

    ${remainingBudget}  Get Budget
    
    Update Wall  0  PAINT2
    
    ${updatedWalls}  Get Walls
    Log  Updated Walls: ${updatedWalls}
    
    ${remainingBudget}  Get Budget
    Log  Remaining Budget after updates: ${remainingBudget}

Test Material Changes on a Floor
    ${floorTypes}  Get Floor Types
    Log  Available Floor Types: ${floorTypes}

    ${remainingBudget}  Get Budget
    
    Update Too Expensive Floor  TILE7

    ${updatedFloor}  Get Floor
    
    ${remainingBudget}  Get Budget

    Update Valid Floor  LAMINATE3

    ${updatedFloor}  Get Floor
    
    ${remainingBudget}  Get Budget
    Log  Remaining Budget after updates: ${remainingBudget}

Test Finished Room
    ${room}  Get Room
    Check Room Data  ${room}

*** Keywords ***
Start Game Request
    [Arguments]  ${width}  ${length}  ${height}  ${budget}
    ${url}  Set Variable  /start
    ${data}  Create Dictionary  width=${width}  length=${length}  height=${height}  budget=${budget}
    ${headers}  Create Dictionary  Content-Type=application/json
    ${response}  POST  ${BASE_URL}${url}  json=${data}  headers=${headers}  expected_status=200
    [Return]  ${response}

Check Start Game Request
    [Arguments]  ${response}
    Should Be Equal As Numbers  ${response.status_code}  200
    Log  Start Game Response: ${response.text}
    
Get Room
    ${response}  GET  ${BASE_URL}/room  ${HEADER}
    [Return]  ${response.text}

Check Room Data
    [Arguments]  ${room}
    Log  Room Data: ${room}
    # Lisää tarkistuksia tarpeen mukaan

Get Budget
    ${response}  GET  ${BASE_URL}/budget  ${HEADER}
    [Return]  ${response.text}

Check Remaining Budget
    [Arguments]  ${remainingBudget}
    Log  Remaining Budget: ${remainingBudget}
    # Lisää tarkistuksia tarpeen mukaan

Get Wall Types
    ${response}  GET  ${BASE_URL}/walls/types  ${HEADER}
    [Return]  ${response.json()}

Update Wall
    [Arguments]  ${id}  ${type}
    ${headers}  Create Dictionary  Content-Type=application/json
    ${response}  PUT  ${BASE_URL}/walls/${id}  data=${type}  headers=${headers}
    Log  Update Wall Response: ${response.text}

Get Walls
    ${response}  GET  ${BASE_URL}/walls  ${HEADER}
    [Return]  ${response.json()}

Get Floor Types
    ${response}  GET  ${BASE_URL}/floor/types  ${HEADER}
    [Return]  ${response.json()}

Get Floor
    ${response}  GET  ${BASE_URL}/floor  ${HEADER}
    [Return]  ${response.json()}

Update Too Expensive Floor
    [Arguments]  ${type}
    ${headers}  Create Dictionary  Content-Type=application/json
    ${response}  PUT  ${BASE_URL}/floor  data=${type}  headers=${headers}  expected_status=406
    Log  Update Floor Response: ${response.text}

Update Valid Floor
    [Arguments]  ${type}
    ${headers}  Create Dictionary  Content-Type=application/json
    ${response}  PUT  ${BASE_URL}/floor  data=${type}  headers=${headers}
    Log  Update Floor Response: ${response.text}