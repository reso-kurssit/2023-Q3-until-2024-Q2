import React from 'react'
import Groups from '../Groups/Groups';
import Reviews from '../Reviews/Reviews';


const Community = () => {
  return (

    
  <div className="page">
      <h2>Yhteisö</h2>

      <p className="read-the-docs">
        Yhteisö-sivun alla arvostelut ja ryhmät.</p>

        {<Groups />}

        {<Reviews />}

  </div>


  );
};

export default Community;