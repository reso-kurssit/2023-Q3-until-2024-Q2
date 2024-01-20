function getWeather() {

    fetch(apiUrl)
      .then(response => response.json())
      .then(data => {
        // pilvisyys, sademäärä ja tuulen nopeus vaikkapa
        const temperature = Math.round(data.main.temp - 273.15); // celsius-asteina
        const weatherDescription = data.weather[0].description;
        const windSpeed = data.wind.speed;
        const snowfall = data.snowfall;
        const visibility = data.visibility;
  
        updateSeppoState(temperature, weatherDescription, windSpeed, snowfall, visibility);
      })
      .catch(error => {
        console.error('Virhe säätietojen hakemisessa:', error);
      });
  }
  
  function updateSeppoState(temperature, weatherDescription, windSpeed, snowfall, visibility) {
    const temperatureThreshold = -15;

    if (temperature > temperatureThreshold) {
        if (weatherDescription.includes('clear')) {
            seppo.weather = 'good';
            //useApproveImages();
        } 
        
        if (weatherDescription.includes('cloud')) {
            seppo.weather = 'good';
            //useApproveImages();
        }
        
        if (weatherDescription.includes('snow')) {
            if (snowfall && snowfall['1h'] > 6) {
                seppo.weather = 'bad';
                //useDenyImages();
            } else {
                seppo.weather = 'neutral';
                //useApproveImages();
            }
        }
    
      if (weatherDescription.includes('rain')) {
        console.log('Sataa!');
        seppo.weather = 'bad';
        //useDenyImages();
      }
    
      if (windSpeed > 10) {
        console.log('Tuulee kovaa!');
        seppo.weather = 'bad';
        //useDenyImages();
      }

      if (visibility && visibility < 1000) {
        console.log('Huono näkyvyys!');
        seppo.weather = 'bad';
        //useDenyImages();
      }
    } else {
        seppo.weather = 'bad';
        //useDenyImages();
    }
}

function useDenyImages() {
    updateRandomSeppoByCategory('seppo-container', 'seppo-walks-deny');
}

function useApproveImages() {
    updateRandomSeppoByCategory('seppo-container', 'seppo-walks');
}

  window.onload = getWeather;