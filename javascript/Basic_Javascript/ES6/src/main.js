function one(){
    var x = 10;
    if( x < 20){
        var y = 4;
        if( y < 5 && x < 15 ){
            var z = 'Hello';
            console.log('we can access:',x)
            console.log('we can access:',y)
        }
        console.log('z:',z) // z is defined
    }
}

function uselet(){
    let x = 10;
    if( x < 20){
        let y = 4;
        if( y < 5 && x < 15 ){
            let z = 'Hello';
            console.log('we can access:',x)
            console.log('we can access:',y)
        }
        //console.log('z:',z) // z is undefined
    }
}

function doubleloop (){
    for(var i = 0; i < 10; i++){
        console.log('inside:',i); // this will only run once.

        for(var i = 0; i < 20; i ++){ //because we declare the same variable here.
            console.log('i:',i);
        }
    }
}

function constObject (){
    const a = 10;
    const b = [1,2,3];
    const c = {x:5};

    // a = a+2;        // this is not ok.

    b[1] = 4;       // this is ok.
    // b = [3,4,5];    // this is not ok.
    b.push(5);      // this is ok.
    b[4] = 10;      // this is ok.

    c.x = 10;       // this is ok.
    c.b = 69;       // this is ok.
    c = {a:'10'}    // this is not ok.
    console.log(`a:${a}\nb:${b}\nc:${c}`)
}

//console.log(x); //this will cause error
one();
uselet();
// doubleloop();
constObject();