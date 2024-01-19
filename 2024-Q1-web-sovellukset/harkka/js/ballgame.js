document.addEventListener("DOMContentLoaded", function () {
    seppo.health = localStorage.getItem("seppoHealth") || seppo.maxHealth;

    const ball = document.getElementById('ballgame-ball');
    const jump = document.getElementById('ballgame-jump');

    if (seppo.health <= 20) {
        useSleepImages();
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
        seppo.health -= 3; 
        if (seppo.health < 0) {
            seppo.health = 0;
        }

        if (seppo.health <= 20) {
            useSleepImages();
        }

        localStorage.setItem("seppoHealth", seppo.health);
    }

    function useSleepImages() {
        ball.style.display = 'none';
        jump.style.display = 'none';
        document.querySelector('.seppo-sleeps').style.display = 'block';
    }
});
