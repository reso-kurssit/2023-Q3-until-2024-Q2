
document.addEventListener("DOMContentLoaded", function () {
    var health = seppo.getHealth();

    if (health <= 20) {
        useSleepImages();
    } else {
        seppoGoesOut();
    }

});

    function seppoGoesOut() {

        getWeather();
        
       if (seppo.weather === 'good' || seppo.weather === 'neutral') {
           useApproveImages();
           seppo.setHealth(seppo.getHealth() -2);
       } else if (seppo.weather === 'bad') {
           useDenyImages();
       }
    } 
 
    function useSleepImages() {
        updateRandomSeppoByCategory('seppo-container', 'seppo-sleeps');
    }

 