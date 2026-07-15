import {useState} from 'react'

export default function App(){
  const initial = ['Red Bull', 'Ferrari', 'Toyota']
  const [list, updateList] = useState(initial)

  const filter = (e)=>{
    const filtered = []
      for(let index in initial){
        if(initial[index].toLowerCase().includes(e.target.value.toLowerCase())){
          filtered.push(initial[index])
        }
      }
      updateList(filtered)
  }

  return(
    <div>
      <label>Search: </label>
      <input type="text" onChange={(e) =>filter(e)} />
      <ul>
        {list.map((item,index)=>(
          <li key ={index}>{item}</li>
        ))}
      </ul>
    </div>
  )
}