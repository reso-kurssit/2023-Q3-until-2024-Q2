document.addEventListener("DOMContentLoaded", function () {
    var health = seppo.getHealth();

    getWeather();

});

function useSleepImages() {
    updateRandomSeppoByCategory('seppo-container', 'seppo-sleeps');
    hideStory();
}