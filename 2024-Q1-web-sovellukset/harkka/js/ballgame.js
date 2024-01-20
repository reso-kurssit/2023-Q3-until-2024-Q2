
document.addEventListener("DOMContentLoaded", function () {
    const ball = document.getElementById('ballgame-ball');
    const jump = document.getElementById('ballgame-jump');

    if (seppo.getHealth() <= 20) {
        useSleepImages();
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
        var health = seppo.getHealth() -3; 

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
