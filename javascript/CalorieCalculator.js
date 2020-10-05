let weight = 60
let height = 170
let age = 21
let gender = 'men'

console.log(calculateCalorie(weight, height, age, gender))

function calculateCalorie(weight, height, age, gender){
    weight = Number(weight)
    height = Number(height)
    age = Number(age)
    let bmr

    if(gender == 'men'){
        bmr = 10 * weight + 6.25 * height - 5 * age + 5
    }
    else{
        bmr = 10 * weight + 6.25 * height - 5 * age -161
    }

    if(bmr){
        return bmr
    }
    else{
        return 'Invalid input'
    }
}