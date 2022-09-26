var arr = [[], [], [], [], [], [], [], [], []]

// var arr = [[0,8,0,3,9,7,0,4,0], [0,2,0,0,0,0,7,0,0], [4,0,0,1,0,0,3,5,0], [0,0,0,5,0,9,6,0,0], [], [], [], [], []]

for (var i = 0; i < 9; i++) {
	for (var j = 0; j < 9; j++) {
		arr[i][j] = document.getElementById(i * 9 + j);

	}
}


//var arr = [[0,0,0,0,0,3,0,0,4],[1,0,0,2,8,0,0,0,0],[7,8,9,4,0,6,0,2,3],[0,1,2,0,4,7,0,8,0],[4,0,0,0,9,0,2,0,0],[8,0,7,6,1,2,0,4,0],[5,0,0,0,6,4,0,3,0],[0,0,0,0,3,1,0,0,0],[0,0,3,0,2,5,0,0,0]]

var board = [[], [], [], [], [], [], [], [], []]

function FillBoard(board) {
	for (var i = 0; i < 9; i++) {
		for (var j = 0; j < 9; j++) {
			if (board[i][j] != 0) {
				arr[i][j].innerText = board[i][j]
			}

			else
				arr[i][j].innerText = ''
		}
	}
}

let GetPuzzle = document.getElementById('GetPuzzle')
let SolvePuzzle = document.getElementById('SolvePuzzle')

GetPuzzle.onclick = function () {
	var xhrRequest = new XMLHttpRequest()
	xhrRequest.onload = function () {
		var response = JSON.parse(xhrRequest.response)
		console.log(response)
		board = response.board
		FillBoard(board)
	}
	xhrRequest.open('get', 'https://sugoku.herokuapp.com/board?difficulty=easy')
	//we can change the difficulty of the puzzle the allowed values of difficulty are easy, medium, hard and random
	xhrRequest.send()
}

SolvePuzzle.onclick = () => {
	SudokuSolver(board, 0, 0, 9);
};

// SolvePuzzle.onclick = () => {
// 	sodokoSolver(board);
// };

function isValid(board,i, j, num, n){
	// row col check
	for(let x = 0;x<n;x++){
		if(board[i][j] == num || board[x][j] == num){
			return false;
		}
	}

	//submatrix check
	let rn = Math.sqrt(n);
	let si = i -i%rn;
	let sj = j - j % rn;

	for (let x = si; x < si + rn; x++) {
		for (let y = sj; y < sj + rn; y++) {
			if (board[x][y] == num) {
				return false;
			}
		}
	}
	
	return true;
}



function SudokuSolver(board,i,j,n){
	//base case
	if(i==n){
		FillBoard(board);
		return true;
	}

	/// if we are not insise the board
	if(j == n){
		return SudokuSolver(board,i+1,0,n);
	}

	// if cell is already filled : move ahead
	if(board[i][j] != 0){
		return SudokuSolver(board,i,j+1,n);

	}

	//we tru to fill the cell with an appropariate number
	for(let num =1;num<10;num++){
		if(isValid(board,i,j,num,n)){
			board[i][j] = num;
			let subAns = SudokuSolver(board,i,j+1,n);
			if(subAns){
				return true;
			}
			//backtracking
			board[i][j] = 0;
		}
	}
	return false;
}


// function isValid(board, row, col, k) {
//     for (let i = 0; i < 9; i++) {
//         const m = 3 * Math.floor(row / 3) + Math.floor(i / 3);
//         const n = 3 * Math.floor(col / 3) + i % 3;
//         if (board[row][i] == k || board[i][col] == k || board[m][n] == k) {
//           return false;
//         }
//     }
//     return true;
// }


// function sodokoSolver(data) {
//   for (let i = 0; i < 9; i++) {
//     for (let j = 0; j < 9; j++) {
//       if (data[i][j] == 0) {
//         for (let k = 1; k <= 9; k++) {
//           if (isValid(data, i, j, k)) {
//             data[i][j] = `${k}`;
//           if (sodokoSolver(data)) {
//            return true;
//           } else {
//            data[i][j] = 0;
//           }
//          }
//        }
//        return false;
//      }
//    }
//  }
//  return true;
// }