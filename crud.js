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