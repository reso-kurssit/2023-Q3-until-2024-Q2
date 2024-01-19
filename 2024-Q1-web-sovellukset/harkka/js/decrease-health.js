
window.onload = function () {
    seppo.health = localStorage.getItem("seppoHealth") || seppo.maxHealth;

    seppo.health -= 1;
    if (seppo.health < 0) {
        seppo.health = 0;
    }

    localStorage.setItem("seppoHealth", seppo.health);
};

