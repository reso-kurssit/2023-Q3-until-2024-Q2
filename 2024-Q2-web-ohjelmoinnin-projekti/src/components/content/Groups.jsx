import React, { useState } from 'react';

const Groups = () => {
  const [showCreateForm, setShowCreateForm] = useState(false);

  const closeCreateForm = () => {
    setShowCreateForm(false);
  }

  const openCreateForm = () => {
    setShowCreateForm(true);
  }

  const search = () => {
    // logiikka tähän
    alert('Haku suoritettu!');
  }

  const create = () => {
    // logiikka tähän
    alert('Ryhmä luotu!');
  }

  return (
    <div>
      <h2>Ryhmät</h2>
      <p className="info">
        Kirjautuneena käyttäjänä pääset sukeltamaan syvemmälle Muuvin tarjoaman yhteisöllisyyden maailmaan. Liity olemassa oleviin ryhmiin tai luo oma, jossa voit jakaa suosikkikohtauksiasi, keskustella juonikäänteistä tai löytää samanhenkistä leffaporukkaa. Etsi ryhmiä nimillä tai tutustu kuhunkin yksityiskohtaisesti niiden omilla sivuilla.
      </p>

          <b>Etsi ryhmää</b> <br/>
          <input className="field" type="text" placeholder="Hae ryhmää"></input>
          <button onClick={search}>Hae</button> <br/><br/>

      {!showCreateForm ? (
        <a href="#" onClick={openCreateForm}>Tai luo uusi ryhmä</a>
      ) : (
        <div id="createGroup">
          <b>Uusi ryhmä</b> (<a href="#" onClick={closeCreateForm }>Sulje</a>) <br/>
          <p>Ryhmän nimi: <input className="field" type="text" placeholder="Nimi tähän"></input></p>
          <p>Ryhmän kuvaus: <br/>
          <textarea className="box" type="text" placeholder="Kirjoita kuvaus"></textarea></p>
          <button onClick={create}>Luo ryhmä</button> 
        </div>
      )}
      
      <hr />

      <h3>Ryhmät listana [a - z]</h3> 

      <p><a href="#">Ryhmärämä</a></p>
      <p><a href="#">komediahullut</a></p>
      <p><a href="#">tosimiesklubi</a></p>
      <p><a href="#">Stadin Muuvissa</a></p>
      <p><a href="#">SOTA-leffat</a></p>
      <p><a href="#">Dramaqueens</a></p>
      <p><a href="#">kauhalla kauhuu</a></p>
      <p><a href="#">Tampereen seudun leffailijat</a></p>
      <p><a href="#">Leffatiistai</a></p>
      <p><a href="#">Vain-sarjoja</a></p>
      <p><a href="#">Suomalaista filmii</a></p>
      <p><a href="#">lastenleffat</a></p>

      <hr />


    </div>
  );
};

export default Groups;