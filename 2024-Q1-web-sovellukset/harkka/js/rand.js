
document.addEventListener("DOMContentLoaded", function () {

    seppo.setHealth(seppo.getHealth() -1);
    
    var health = seppo.getHealth();
    
    if (health <= 20) {
        useSleepImages();
    } else {
        useRandomImages();
    }

})

function useRandomImages() {
    updateRandomSeppoByCategory('seppo-container', 'seppo-random');
}

function useSleepImages() {
    updateRandomSeppoByCategory('seppo-container', 'seppo-sleeps');
}
