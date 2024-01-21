
document.addEventListener("DOMContentLoaded", function () {
    const ball = document.getElementById('ballgame-ball');
    const jump = document.getElementById('ballgame-jump');

    if (seppo.getHealth() <= 20) {
        useSleepImages();
        document.querySelector('button').disabled = true;
        document.querySelector('input').disabled = true;
        document.querySelector('input').value = 'Ruoki Seppo';


    } else if (seppo.getHealth() >= 20.01) {
        ball;
        jump;
        hideSeppoContainer();
    }

    ball.addEventListener('click', function () {
        tossBall();
        updateHealth();
    });

    function tossBall() {
        ball.style.bottom = '300px';
        jump.style.transform = 'translateX(-50%) translateY(-50px)';

        setTimeout(function () {
            ball.style.bottom = '100px';
            jump.style.transform = 'translateX(-50%)';
        }, 500);
    }

    function updateHealth() {
        var health = seppo.getHealth() -8; 
        
        if (health <= 20) {
            useSleepImages();
        }

        seppo.setHealth(health);
    }

    function useSleepImages() {
        ball.style.display = 'none';
        jump.style.display = 'none';
        document.getElementById('seppo-container').style.display = "block";
        updateRandomSeppoByCategory('seppo-container', 'seppo-sleeps');
    }

    function hideSeppoContainer() {
        document.getElementById('seppo-container').style.display = 'none';
    }

});

document.querySelector('button').addEventListener('click', () => {
    seppo.setHealth(seppo.getHealth() -1);
    const answer = Number(document.querySelector('input').value);
    const correctAnswer = 4;
    
    if (answer === correctAnswer) {
        alert ('Vastasit oikein, 4 linkkiä piilotettu');
    } else {
        alert ('Vastasit väärin, yritä uudelleen')
    }

})

