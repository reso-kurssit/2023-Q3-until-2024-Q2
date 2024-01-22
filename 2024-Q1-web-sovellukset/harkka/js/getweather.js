function getWeather() {

  fetch(apiUrl)
    .then(response => response.json())
    .then(data => {
      const temperature = Math.round(data.main.temp - 273.15);
      const weatherDescription = data.weather[0].description;
      const windSpeed = data.wind.speed;
      const snowfall = data.snowfall;
      const clouds = data.clouds;
      const visibility = data.visibility;

      setTemperature(temperature);
      setWindSpeed(windSpeed);

      updateWeatherDescriptions(temperature, weatherDescription, windSpeed, clouds, visibility);
      updateSeppoState(temperature, weatherDescription, windSpeed, snowfall, visibility);
    })
    .catch(error => {
      console.error('säätietojen haku feilasi', error);
    });
}

function updateWeatherDescriptions(temperature, weatherDescription, windSpeed, clouds, visibility) { 
  if (clouds['all'] < 5) {
    setWeatherClear();
  } else if (clouds['all'] > 50) {
    setWeatherCloud();
  } else {
    setWeatherFewClouds();
  }

  if (snow) {
    setWeatherSnow();
  } else if (snow['1h'] > 6) {
    setWeatherSnowHeavy();
  }

  if (weatherDescription.includes('mist')) {
    setWeatherMist();
  }

  if (weatherDescription.includes('rain')) {
    setWeatherRain();
  } else if (weatherDescription.includes('thunderstorm')) {
    setWeatherStorm();
  }

  if (windSpeed > 11) {
    setWeatherWindHeavy();
  }

  if (visibility && visibility < 1000) {
    setWeatherWeakVisibility();
  }
  
  if (temperature < -20 || temperature > 30) { 
    setTemperatureAlert();
  }
}

function updateSeppoState(temperature, weatherDescription, windSpeed, snowfall, visibility) {

  var health = seppo.getHealth();
  
  if (health <= 20) {
    useSleepImages();
  } else {
    var weatherIsOk = true;

    if (weatherDescription.includes('snow')) {
        if (snowfall && snowfall['1h'] > 6) {
            setWeatherSnowHeavy();
            weatherIsOk = false;
        }
    }

    if (weatherDescription.includes('rain')) {
      console.log('Sataa!');
      weatherIsOk = false;
    }

    if (windSpeed > 24) {
      console.log('Tuulee kovaa!');
      weatherIsOk = false;
    }

    if (visibility && visibility < 1000) {
      console.log('Huono näkyvyys!');
      weatherIsOk = false;
    }

    if (temperature < -20 || temperature > 30) { 
      weatherIsOk = false;
    }

    if (weatherIsOk) {
      useApproveImages();
    } else {
      useDenyImages();
    }
  }

} 

function useDenyImages() {
  updateRandomSeppoByCategory('seppo-container', 'seppo-walks-deny');
  hideStory();
}

function useApproveImages() {
  updateRandomSeppoByCategory('seppo-container', 'seppo-walks');
  seppo.setHealth(seppo.getHealth() * 25/100);
  showStory();
}

function setWeatherWindHeavy() {
  document.getElementById('wind').classList.add('custom-emoji-50');
  document.getElementById('desWind').innerHTML = '';
}

function setWeatherSnow() {
  document.getElementById('snow').classList.add('custom-emoji-53');
  document.getElementById('desSnow').innerHTML = 'Lumisadetta';
}

function setWeatherSnowHeavy() {
  document.getElementById('snow').classList.add('custom-emoji-53');
  document.getElementById('desSnowHeavy').innerHTML = 'Runsasta lumisadetta';
}

function setWeatherRain() {
  document.getElementById('rain').classList.add('custom-emoji-52');
  document.getElementById('desRain').innerHTML = 'Sateista';
}

function setWeatherCloud() {
  document.getElementById('cloud').classList.add('custom-emoji-54');
  document.getElementById('desCloud').innerHTML = 'Pilvistä';
}

function setWeatherFewClouds() {
  document.getElementById('cloud').classList.add('custom-emoji-79');
  document.getElementById('desCloud').innerHTML = 'Puolipilvistä';
}

function setWeatherClear() {
  document.getElementById('cloud').classList.add('custom-emoji-51');
  document.getElementById('desCloud').innerHTML = 'Selkeää';
}

function setWeatherMist() {
  document.getElementById('mist').classList.add('custom-emoji-80');
  document.getElementById('desMist').innerHTML = 'Sumuista';
}

function setWeatherStorm() {
  document.getElementById('storm').classList.add('custom-emoji-81');
  document.getElementById('desStorm').innerHTML = 'Myrskyisää';
}

function setWeatherWeakVisibility() {
  document.getElementById('esVisibilityAlert').innerHTML = 'Heikko näkyvyys';
}

function setTemperatureAlert() {
  document.getElementById('desTemperatureAlert').innerHTML = 'Lämpötilarajat -20 ja +30';
}

function setTemperature(temperature) {
  var temperatureElement = document.getElementById('desTemperature');
  if (temperatureElement) {
    temperatureElement.innerHTML = `Lämpötila ${temperature} °C`; 
  }
}

function setWindSpeed(windSpeed) {
  var speedElement = document.getElementById('desSpeed');
  if (speedElement) {
    speedElement.innerHTML = `Tuuli ${windSpeed} m/s`; 
  }
}

function hideStory() {
  var storyElements = document.getElementsByClassName('story');
  for (var i = 0; i < storyElements.length; i++) {
    storyElements[i].classList.add('hide');
  }
}

function showStory() {
  var storyElements = document.getElementsByClassName('story');
  for (var i = 0; i < storyElements.length; i++) {
    storyElements[i].classList.remove('hide');
  }
}
