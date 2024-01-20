document.addEventListener("DOMContentLoaded", function () {

    useWaitingImages();
    updateHealthBar();

    var emojiElements = document.querySelectorAll('.custom-emoji');
    
    emojiElements.forEach(function (emoji) {
        emoji.addEventListener('click', function () {
            var emojiClass = emoji.classList[0];
            feedSeppo(emojiClass);
        });
    });

});

function feedSeppo(food) {

    if (food.startsWith("custom-emoji-")) {
        var likedFoods = ["custom-emoji-20", "custom-emoji-21", "custom-emoji-22", "custom-emoji-23", "custom-emoji-24", "custom-emoji-25", "custom-emoji-26", "custom-emoji-27", "custom-emoji-28", "custom-emoji-30", "custom-emoji-31", "custom-emoji-32", "custom-emoji-33", "custom-emoji-34", "custom-emoji-35", "custom-emoji-36"]; 
        var dislikedFoods = ["custom-emoji-10", "custom-emoji-11", "custom-emoji-12", "custom-emoji-13", "custom-emoji-14", "custom-emoji-15", "custom-emoji-16", "custom-emoji-17", "custom-emoji-18", "custom-emoji-19", "custom-emoji-29", "custom-emoji-37", "custom-emoji-38"];

        if (likedFoods.includes(food)) {
            seppo.setHealth(seppo.getHealth() +4);
            updateHealthBar();
            useEatsImages();
        } else if (dislikedFoods.includes(food)) {
            useEatsDenyImages();
        }
    } else {
        // err
    }
}

function updateHealthBar() {
    var healthbar = document.getElementById("current-health");
    var healthtext = document.getElementById("healthtext");

    healthbar.style.width = seppo.getHealth()  + "%";
    
    var roundedPercentage = seppo.getHealth().toFixed(2);
    healthtext.textContent = roundedPercentage + "%";

    var energyPercentage = seppo.getHealth();

    if (energyPercentage >= 0 && energyPercentage <= 20) {
        healthbar.style.background = '#ff0000'; 
    } else if (energyPercentage > 10 && energyPercentage <= 40) {
        healthbar.style.background = '#ffff00'; 
    } else if (energyPercentage > 40 && energyPercentage <= 100) {
        healthbar.style.background = '#00ff00'; 
    }
}

function useWaitingImages() {
    updateRandomSeppoByCategory('seppo-container', 'seppo-waiting');
}

function useEatsImages() {
    updateRandomSeppoByCategory('seppo-container', 'seppo-eats');
}

function useEatsDenyImages() {
    updateRandomSeppoByCategory('seppo-container', 'seppo-eats-deny');
}