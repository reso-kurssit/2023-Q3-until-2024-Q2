import React, { useState, useEffect } from 'react';

const Home = () => {

  const [backgroundIndex, setBackgroundIndex] = useState(0);
  const backgrounds = [
    'url(/images/backdrops/bd1.png)',
    'url(/images/backdrops/bd2.png)',
    'url(/images/backdrops/bd3.png)',
    'url(/images/backdrops/bd4.png)',
    'url(/images/backdrops/bd5.png)',
    'url(/images/backdrops/bd6.png)',
    'url(/images/backdrops/bd7.png)',
    'url(/images/backdrops/bd8.png)',
    'url(/images/backdrops/bd9.png)',
    'url(/images/backdrops/bd10.png)',
    'url(/images/backdrops/bd11.png)',
    'url(/images/backdrops/bd12.png)',
    'url(/images/backdrops/bd13.png)',
    'url(/images/backdrops/bd14.png)',
    'url(/images/backdrops/bd15.png)',
    'url(/images/backdrops/bd16.png)',
    'url(/images/backdrops/bd17.png)',
    'url(/images/backdrops/bd18.png)',
    'url(/images/backdrops/bd19.png)',
    'url(/images/backdrops/bd20.png)',
    'url(/images/backdrops/bd21.png)',
    'url(/images/backdrops/bd22.png)',
    'url(/images/backdrops/bd23.png)',
    'url(/images/backdrops/bd24.png)',

  ];

  useEffect(() => {
    const interval = setInterval(() => {
      setBackgroundIndex(prevIndex => (prevIndex + 1) % backgrounds.length);
    }, 8500); 

    return () => clearInterval(interval);    
  }, [backgrounds.length]);

  const bgStyle = {
    backgroundImage: backgrounds[backgroundIndex],

  };

  return (

    <div className="page">

    <div className="movieBg" style={bgStyle}></div> <br/>


      <h2>Tervetuloa Muuvi -palveluun! </h2>

      <p>
      Kaipaatko paikkaa, jossa intohimo elokuviin ja sarjoihin yhdistää meidät kaikki? </p>

      <p>
      Muuvi on portti jännittävään yhteisöön, missä voit liittyä ryhmiin, jakaa ajatuksiasi leffoista ja sarjoista ryhmächateissa, sekä lukea ja kirjoittaa arvosteluja. Lisäksi tarjoamme ainutlaatuisen Finnkino -elokuvanäytöshakumme sekä kattavan leffahakumme, joiden avulla löydät helposti juuri sinua kiinnostavat elokuvat ja sarjat.
      </p>


      <p>
      Täällä yhteisöllisyys kohtaa elokuvien ja sarjojen maailman – tervetuloa kotiin elokuvafanien paratiisiin. Tervetuloa Muuviin.
      </p>

      <p className="info">
        Muuvi on OAMK tietotekniikan opiskelijoiden tekemä elokuvasovellusprojekti. Tarkoituksena on luoda leffaharrastajille sivusto. <br/>
        Sovellus hyödyntää avoimen datan lähteitä ja sille tehdään oma palvelin ja tietokanta datan hallintaan. <br/>
      </p>


    </div>

  );
};

export default Home;