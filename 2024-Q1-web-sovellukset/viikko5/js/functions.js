function diceRandom() { 
    return Math.floor(Math.random() * 6) + 1;
}

function rollDice() {
    var diceDiv = document.getElementById('dice');
    var diceImg = diceDiv.querySelector('img');
    var randomNumber = diceRandom();

    diceImg.src = 'img/' + randomNumber + '.png';
}