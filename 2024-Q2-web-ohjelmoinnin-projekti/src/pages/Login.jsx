import React from 'react'
import Register from '@content/Register';

const Login = () => {

    const login = () => {
      // logiikka tähän
      alert('click');
    }

  return (

    <div className="page">

        <h2>Kirjautuminen</h2>

        <p class="info">Älä koskaan jää käyttäjätunnusta ja salasanaasi ulkopuolisille.</p>


        <p>Nimimerkki: <input className="field" type="text" placeholder="Valitse nimimerkki"></input></p>
          <p>Salasana: <input className="field" type="text" placeholder="Valitse salasana"></input></p>
          <button onClick={login}>Kirjaudu sisään</button> 

          <br/> <br/>


        {<Register />}


    </div>

  );
};

export default Login;