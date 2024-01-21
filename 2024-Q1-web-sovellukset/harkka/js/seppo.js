var seppo = {

    getHealth: function() {
        return parseInt(localStorage.getItem("seppoHealth") || 100 ) ;
    },

    setHealth: function(health) {
        console.log(health);

        if (health < 0) {
            health = 0;
        } else if (health > 100) {
            health = 100;
        }
        console.log(health);

        localStorage.setItem("seppoHealth", health);
    }
};