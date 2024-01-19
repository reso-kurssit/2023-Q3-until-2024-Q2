window.onload = function() {
    var savedHealth = localStorage.getItem("seppoHealth");
    if (savedHealth !== null) {
        seppo.health = parseInt(savedHealth);
        updateHealthBar();
    }
}