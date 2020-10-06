let string = "Hello World!"

console.log(reverse(string))

function reverse(str){
    let reversed = ''
    for(let i = str.length - 1; i >= 0; i--){
        reversed += str[i]
    }
    return reversed
}