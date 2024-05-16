const fs = require('fs');

// fs.readFile('text.txt', 'utf8', (err, data) => {
//     if (err) {
//         console.log(err);
//     } else {
//         console.log(data);
//     }
// });

// const add = 'Nah just kidding i am noob as fuck:D';
// fs.writeFile('text.txt', add, (err) => {
//     if (err) {
//         console.log(err);
//     }
// });

// const appendData = '\nHahahaha you thought i am bad';
// fs.appendFile('text.txt', appendData, (err) => {
//     if (err) {
//         console.log(err);
//     }
// })

// fs.readFile('text.txt', 'utf8', (err, data) => {
//     if (err) console.log(err);
//     const updated = data.replace('bad', 'good');
//     fs.writeFile('text.txt', updated, (err) => {
//         if (err) {
//             console.log(err);
//         }
//     })
// })

fs.unlink('text.txt', (err) => {
    if (err) {
        console.log(err);
    }
    console.log("Deleted");
});
