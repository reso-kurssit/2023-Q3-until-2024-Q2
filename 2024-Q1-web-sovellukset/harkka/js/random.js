var seppoPairs = [
    // seppo-index
    { image: "./img/luv.png", message: "Olen Seppo, virtuaalinen corgi. Pidän täällä sinulle mielelläni seuraa. Aivan ihana kun olen!", category: "seppo-index" },
    { image: "./img/butt2.png", message: "Olen Seppo, virtuaalinen corgi. Pidän täällä sinulle mielelläni seuraa. Aivan ihana kun olen!", category: "seppo-index" },
    { image: "./img/smile.png", message: "Olen Seppo, virtuaalinen corgi. Pidän täällä sinulle mielelläni seuraa. Aivan ihana kun olen!", category: "seppo-index" },
    { image: "./img/wink.png", message: "Olen Seppo, virtuaalinen corgi. Pidän täällä sinulle mielelläni seuraa. Aivan ihana kun olen!", category: "seppo-index" },
    { image: "./img/kind.png", message: "Olen Seppo, virtuaalinen corgi. Pidän täällä sinulle mielelläni seuraa. Aivan ihana kun olen!", category: "seppo-index" },
    { image: "./img/laying.png", message: "Olen Seppo, virtuaalinen corgi. Pidän täällä sinulle mielelläni seuraa. Aivan ihana kun olen!", category: "seppo-index" },
    { image: "./img/scrub.png", message: "Olen Seppo, virtuaalinen corgi. Pidän täällä sinulle mielelläni seuraa. Aivan ihana kun olen!", category: "seppo-index" },
    // seppo-waiting
    { image: "./img/kind.png", message: "Tosi nätisti osaan odottaa", category: "seppo-waiting" },
    { image: "./img/kind.png", message: "Mitäs nyt vuorossa", category: "seppo-waiting" },
    { image: "./img/smile.png", message: "Olen valmis!", category: "seppo-waiting" },
    { image: "./img/wakey.png", message: "Veeeenytys.. ja valmiina ollaan!", category: "seppo-waiting" },
    { image: "./img/run.png", message: "Täällä jo! En malta odottaa!", category: "seppo-waiting" },
    { image: "./img/laying.png", message: "Tässä olen, valmiina jo!", category: "seppo-waiting" },
    { image: "./img/laying.png", message: "Hei ihminen, mitäs nyt?", category: "seppo-waiting" },
    // seppo-eats + seppo-eats-deny 
    { image: "./img/angry.png", message: "Mitä pskaa sä yrität mulle syöttää? Syö ihan ite!", category: "seppo-eats-deny" },
    { image: "./img/angry.png", message: "Ootko kuullut koskaan lajityypillisestä ruokinnasta? Tää ei ole sitä!", category: "seppo-eats-deny" },
    { image: "./img/eat.png", message: "Om nom... nom..", category: "seppo-random", category: "seppo-eats"},
    { image: "./img/eat.png", message: "*crunch, crunch*, hyvääää!", category: "seppo-eats"},
    { image: "./img/luv.png", message: "Niin hyvää on!", category: "seppo-eats"},
    { image: "./img/luv.png", message: "Ihan supernamia!", category: "seppo-eats"},
    { image: "./img/yummy.png", message: "Maistuu, se on varma nakki!", category: "seppo-eats"},
    { image: "./img/yummy.png", message: "Namsssskisss", category: "seppo-eats"},
    { image: "./img/eat.png", message: "Nam.. nom, om..", category: "seppo-eats"},
    { image: "./img/sad.png", message: "Yäk, hyi.. ei kiitos", category: "seppo-eats-deny" },
    { image: "./img/sad.png", message: "En halua tuota tällä kertaa", category: "seppo-eats-deny" },
    { image: "./img/sad.png", message: "Toi on pahaa", category: "seppo-eats-deny" },
    { image: "./img/frustrated.png", message: "Oisko jotain muuta syötävää?", category: "seppo-eats-deny" },
    { image: "./img/frustrated.png", message: "Tiekkö, että tuo ei oikeen maistu..", category: "seppo-eats-deny" },
    { image: "./img/frustrated.png", message: "Käviskö koiranruoka tähteiden sijaan?", category: "seppo-eats-deny" },
    // seppo-walks + seppo-walks-deny ( + some random)
    { image: "./img/angry.png", message: "En todellakaan lähe mihinkään ulos tolla kelillä!", category: "seppo-walks-deny" },
    { image: "./img/angry.png", message: "Mee vaan keskenäs, ootko kattonu säätä viimeaikoina??", category: "seppo-walks-deny" },
    { image: "./img/butt.png", message: "Täs mä vaan kävelen...", category: "seppo-random", category: "seppo-walks" },
    { image: "./img/butt.png", message: "Jee, nyt mennään", category: "seppo-random", category: "seppo-walks" },
    { image: "./img/run.png", message: "Ulooooos, wuhuuu!", category: "seppo-random", category: "seppo-walks" },
    { image: "./img/run.png", message: "Ulos pissalle, uuuulos pissalle, ouuuuuuu jeah!", category: "seppo-random", category: "seppo-walks" },
    { image: "./img/frighten.png", message: "Ihan aivan totaalisen kamala keli!", category: "seppo-walks-deny" },
    { image: "./img/frustrated.png", message: "Ei tuonne uskalla mennä.. oisko huomenna parempi keli?", category: "seppo-walks-deny" },
    { image: "./img/frustrated.png", message: "Älä pliiiiiis pakota mua lähtee ulos tällä säällä", category: "seppo-walks-deny" },
    { image: "./img/cry.png", message: "Jos vaan pysytään sisällä, sopiiko?", category: "seppo-walks-deny" },
    { image: "./img/laying2.png", message: "Tänään ei vaan huvittas lähteä", category: "seppo-walks-deny" },
    { image: "./img/pfff.png", message: "Taivaalta sataa pskaa, ja odotat mun lähtevän ulos??", category: "seppo-walks-deny" },
    { image: "./img/pfff.png", message: "Tänään me ei kuule ulkoilla", category: "seppo-walks-deny" },
    // seppo-plays + seppo-plays-deny ( + some random)
    { image: "./img/play.png", message: "Leikitääks?", category: "seppo-random", category: "seppo-plays" },
    { image: "./img/run.png", message: "Et ikinä saa mua kiinni!", category: "seppo-random", category: "seppo-plays" },
    // seppo-sleeps ( + some random)
    { image: "./img/butt3.png", message: "Vähän tässä ehkä väsyttäisi.", category: "seppo-random", category: "seppo-sleeps"  },
    { image: "./img/dud.png", message: "Miten ois se kauan kaivattu ruoka?", category: "seppo-sleeps" },
    { image: "./img/dud.png", message: "Tahtoo rrruokaa...", category: "seppo-sleeps" },
    { image: "./img/dud.png", message: "Joo, nousen ihan kohta.. ehkä..", category: "seppo-sleeps" },
    { image: "./img/fell.png", message: "Zzz....", category: "seppo-random", category: "seppo-sleeps" },
    { image: "./img/fell.png", message: "Anna mä nukun, jos et muutu mulle energiaksi", category: "seppo-sleeps" },
    { image: "./img/sleepy.png", message: "Z..Z..zz.z..z.z", category: "seppo-random", category: "seppo-sleeps" },
    { image: "./img/sleepy2.png", message: "Zzz.z.z...zzz", category: "seppo-random", category: "seppo-sleeps" },
    { image: "./img/laying2.png", message: "Anna mun heeetki vielä kerätä voimia", category: "seppo-sleeps" },
    // seppo-random 
    { image: "./img/angry.png", message: "Pyh! Jos haluan syödä sun kengät, niin minähän syön ne.", category: "seppo-random" },
    { image: "./img/butt2.png", message: "Mitä asiaa? Hä!", category: "seppo-random" },
    { image: "./img/confused.png", message: "Siis mitä? .. ihmettä? Tässä nyt öäää tapahtuu?", category: "seppo-random" },
    { image: "./img/cool.png", message: "Ota ihan iisisti.", category: "seppo-random" },
    { image: "./img/cool.png", message: "Enks ookki pähee", category: "seppo-random" },
    { image: "./img/cool.png", message: "Siis mä sain tällaset. Maailman siisteimmät pokat hei!", category: "seppo-random" },
    { image: "./img/cry.png", message: "Ei. En tykkää!", category: "seppo-random" },
    { image: "./img/dud.png", message: "Leikin vaan kosahtanutta.. älä huomaa mua, jooko.", category: "seppo-random" },
    { image: "./img/flap.png", message: "Flapitiflap!", category: "seppo-random" },
    { image: "./img/flap.png", message: "Halloo! Huomaakko muaa?", category: "seppo-random" },
    { image: "./img/frighten.png", message: "Ei, ei, ei, ei, ei, et voi tehdä näin mulle, ei, ei! Ei!", category: "seppo-random" },
    { image: "./img/frustrated.png", message: "Ohhoi.. en jaksaisi mennä ulos nyt.", category: "seppo-random" },
    { image: "./img/gift.png", message: "Ylläriiiiipyllärii!!", category: "seppo-random" },
    { image: "./img/grin.png", message: "Kekeke...", category: "seppo-random" },
    { image: "./img/itch.png", message: "Aiiiiii, kun kutittaa! Ärr-r-rr", category: "seppo-random" },
    { image: "./img/joy.png", message: "Haluun uuden lelun, saanhan? Saanhan?!", category: "seppo-random" },
    { image: "./img/kind.png", message: "Tahtoo jotain hyvää!", category: "seppo-random" },
    { image: "./img/kind.png", message: "Olen ollut superkiltisti tänään", category: "seppo-random" },
    { image: "./img/laying.png", message: "Que? Jotain asiaa? Mulle vai?", category: "seppo-random" },
    { image: "./img/laying2.png", message: "Nousen ihan kohta..", category: "seppo-random" },
    { image: "./img/leave.png", message: "Emmä nyt jaksa.", category: "seppo-random" },
    { image: "./img/lurk.png", message: "Kukkuu?", category: "seppo-random" },
    { image: "./img/luv.png", message: "Tää on ihanaa, kaikki on ihanaa!", category: "seppo-random" },
    { image: "./img/naur.png", message: "WHAHAHAHAHAHAHA!", category: "seppo-random" },
    { image: "./img/party.png", message: "Sopiiko, että ois mun synttärit nyt?", category: "seppo-random" },
    { image: "./img/peek.png", message: "Hellouuuu..", category: "seppo-random" },
    { image: "./img/pfff.png", message: "Ei kettu...", category: "seppo-random" },
    { image: "./img/sad.png", message: "Mä en oikeen tiiä miks, mut.. mua ehkä vähän surettaa vaan", category: "seppo-random" },
    { image: "./img/scrub.png", message: "Rrr-r-r.. tää.. rapsuttaa mukavasti!", category: "seppo-random" },
    { image: "./img/smile.png", message: "Kivaa! On!", category: "seppo-random" },
    { image: "./img/surprise.png", message: "Jullatuuuuuus!!", category: "seppo-random" },
    { image: "./img/thirsty.png", message: "Oivoiv..puuh... juoksin niin nopeesti ku... puuuh... kerkesin tänne.. huh!", category: "seppo-random" },
    { image: "./img/wakey.png", message: "Joskohan tässä heräilisi, juu!", category: "seppo-random" },
    { image: "./img/wash.png", message: "Puhdas koira on hieno koira!", category: "seppo-random" },
    { image: "./img/wash.png", message: "Kävin vähän leikkimässä mudassa Hakukenttä-aukiolla. Pesulla lika lähtee!", category: "seppo-random" },
    { image: "./img/wink.png", message: "Hei, oot sie aika hassu!", category: "seppo-random" },
    { image: "./img/yummy.png", message: "Jaa, meinasitko ehkä mulle ruokasi antaa?", category: "seppo-random" },
];

function getRandomSeppoPairByCategory(category) {
    var filteredSeppos = seppoPairs.filter(seppo => seppo.category === category);
    var randomIndex = Math.floor(Math.random() * filteredSeppos.length);

    return filteredSeppos[randomIndex];
}
function updateRandomSeppoByCategory(container, category) {
    var seppoContainer = document.getElementById(container);

    if (seppoContainer !== null) {
        
        var randomSeppoPair = getRandomSeppoPairByCategory(category);

        seppoContainer.innerHTML = `
            <img class="tiny" src="${randomSeppoPair.image}" /> <br>
            <small>${randomSeppoPair.message}</small>
        `;
    } else {
        console.error("No Seppo containers found for category: " + category);
    }
}

