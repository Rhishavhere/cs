const fs = require('fs')
const path = require('path')

const folder = path.join(__dirname, 'demo')

if(!fs.existsSync(folder)){
  fs.mkdirSync(folder)
}

const filename = 'example.txt'
const filePath = path.join(folder,filename)

const createFile = (data, callback) =>{
  fs.writeFile(filePath, data, err=>{
    if(err){
      callback(err)
      return
    }
    callback(null,'Written')
  })
}

const readFile = (callback) =>{
  fs.readFile(filePath, 'utf8', (err, data)=>{
    if(err){
      callback(err)
      return
    }
    callback(null, data)
  })
}

const updateFile = (data, callback) =>{
  fs.writeFile(filePath, data, err=>{
    if(err){
      callback(err)
      return
    }
    callback(null,'Updated')
  })
}

const deleteFile = (callback) =>{
  fs.unlink(filePath, err=>{
    if(err){
      callback(err)
      return
    }
    callback(null,'Deleted')
  })
}

createFile('Hi', (err, message) =>{
  if(err){
    console.error('Error: ', err)
    return
  }
  console.log(message)

  readFile((err, message)=>{
    if(err){
      console.error('Error: ', err)
      return
    }
    console.log('Content: ', message)

    updateFile('Welcome', (err,message)=>{
      if(err){
        console.error('Error: ', err)
        return
      }
      console.log(message)

      readFile((err, message)=>{
        if(err){
          console.error('Error: ', err)
          return
        }
        console.log('Content: ', message)

        deleteFile((err,message)=>{
          if(err){
            console.error('Error: ', err)
            return
          }
          console.log(message)
        })

      })
    })
  })
})

// OR

// const fs = require('fs');
// const path = require('path');

// const filePath = path.join(__dirname, 'myFile.txt'); //

// const content = 'Hello, world!';
// const newContent = 'This is the updated content.';

// fs.writeFileSync(filePath, content);
// console.log('File created successfully');

// const data = fs.readFileSync(filePath, 'utf-8');
// console.log(`File contents: ${data}`);

// fs.writeFileSync(filePath, newContent);
// console.log('File updated successfully');

// fs.unlinkSync(filePath);
// console.log('File deleted successfully');






// const fs = require('fs/promises')
// const path = require('path')

// const folder = path.join(__dirname, 'demo')
// const filePath = path.join(folder, 'example.txt')

// async function run() {
//   try {
//     // Ensure folder exists
//     await fs.mkdir(folder, { recursive: true })

//     // Create
//     await fs.writeFile(filePath, 'Hi')
//     console.log('Written')

//     // Read
//     let data = await fs.readFile(filePath, 'utf8')
//     console.log('Content:', data)

//     // Update
//     await fs.writeFile(filePath, 'Welcome')
//     console.log('Updated')

//     // Read again
//     data = await fs.readFile(filePath, 'utf8')
//     console.log('Content:', data)

//     // Delete
//     await fs.unlink(filePath)
//     console.log('Deleted')

//   } catch (err) {
//     console.error('Error:', err)
//   }
// }

// run()