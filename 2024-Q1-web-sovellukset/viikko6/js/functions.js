const input = document.querySelector('input')
input.maxLength = 50;
const list = document.querySelector('table')
const sort = document.querySelector('span')
const todos = []
const colgroup = document.createElement('colgroup')
const col1 = document.createElement('col')
const col2 = document.createElement('col')

col1.style.width = '10%'
col2.style.width = '90%'

colgroup.appendChild(col1)
colgroup.appendChild(col2)

list.appendChild(colgroup)

const addRow = () => {
    const newTodo = input.value
    todos.push (newTodo)

    const row = list.insertRow()
    const col1 = row.insertCell(0)
    const col2 = row.insertCell(1)

    col1.innerHTML = '<a href="#" onClick="deleteRow(\'' + newTodo + '\')">X</a>'
    col2.innerHTML = newTodo

    input.maxLength = 50
    input.value = ''
}

input.addEventListener('keypress', (event) => {

    if (event.key === 'Enter') {
        addRow()
    }
})

const deleteRow = (todo) => {
    const index = todos.indexOf(todo)
    todos.splice(index, 1)
    list.deleteRow(index)
}

const addTableRow = (text) => {
    const row = list.insertRow()
    const col1 = row.insertCell(0)
    const col2 = row.insertCell(1)

    col1.innerHTML = '<a href="#" onClick="deleteRow(\'' + text + '\')">X</a>'
    col2.innerHTML = text
}

sort.addEventListener ('click', () => {
    todos.sort ()
    for (let i = todos.length - 1; i >= 0; i--) {
        list.deleteRow(i)
    }

    for (let i = 0; i < todos.length; i++) {
        addTableRow (todos[i])
    }
})