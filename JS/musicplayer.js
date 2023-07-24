const musicContainer = document.getElementById('music-container')
const playBtn = document.getElementById('play')
const prevBtn = document.getElementById('prev')
const nextBtn = document.getElementById('next')

const audio = document.getElementById('audio')
const progress = document.getElementById('progress')
const progressContainer = document.getElementById('progress-container')
const title = document.getElementById('title')
const cover = document.getElementById('cover')
const currTime = document.querySelector('#currTime')
const durTime = document.querySelector('#durTime')

// Song titles
const songs = ['Blood', 'Hell', 'UNHOLY_CRUSADE', 'BFG', 'Duality', 'Psychosocial', 'Before_I_Forget', 'Cu_dedicatie_pentru_Edmond']

// Keep track of song
let songIndex = 0

// Initially load song details into DOM
loadSong(songs[songIndex])

// Update song details
function loadSong(song) {
  // @ts-ignore
  title.innerText = song

  // @ts-ignore
  audio.src = `${song}.mp3`

  // @ts-ignore
  // cover.src = `${song}.png`;
  if (songIndex <= 3) {

    // @ts-ignore
    cover.src = `Doom.png`

  } else if (songIndex > 3 && songIndex < 7) {

    // @ts-ignore
    cover.src = `slipknot.png`

  } else {
    // @ts-ignore
    cover.src = `Cu_dedicatie_pentru_Edmond.png`

  }
}

// Play song
function playSong() {
  // @ts-ignore
  musicContainer.classList.add('play')

  // @ts-ignore
  playBtn.querySelector('img.play').classList.remove('hidden')

  // @ts-ignore
  playBtn.querySelector('img.pause').classList.add('hidden')

  // @ts-ignore
  audio.play()
}

// Pause song
function pauseSong() {
  // @ts-ignore
  musicContainer.classList.remove('play')

  // @ts-ignore
  playBtn.querySelector('img.play').classList.add('hidden')

  // @ts-ignore
  playBtn.querySelector('img.pause').classList.remove('hidden')

  // @ts-ignore
  audio.pause()
}
// Previous song
function prevSong() {
  songIndex--
  if (songIndex < 0) {
    songIndex = songs.length - 1
  }

  loadSong(songs[songIndex])
  playSong()

}
// Next song
function nextSong() {
  songIndex++
  if (songIndex > songs.length - 1) {
    songIndex = 0
  }

  loadSong(songs[songIndex])
  playSong()
}
// Update progress bar
function updateProgress(e) {
  const { duration, currentTime } = e.srcElement
  const progressPercent = (currentTime / duration) * 100;

  // @ts-ignore
  progress.style.width = `${progressPercent}%`

}
// Set progress bar
function setProgress(e) {
  const width = this.clientWidth
  const clickX = e.offsetX

  // @ts-ignore
  const duration = audio.duration

  // @ts-ignore
  audio.currentTime = (clickX / width) * duration
}
//get duration & currentTime for Time of song
function DurTime (e) {
	const {duration,currentTime} = e.srcElement
	var sec
  var sec_d
  
	// define minutes currentTime
	let min = (currentTime==null)? 0:
    Math.floor(currentTime / 60);
  
	// @ts-ignore
	min = min <10 ? '0'+min:min

	// define seconds currentTime
	function get_sec (x) {
		if(Math.floor(x) >= 60){
			
			for (var i = 1; i<=60; i++){
				if(Math.floor(x)>=(60*i) && Math.floor(x)<(60*(i+1))) {
					sec = Math.floor(x) - (60*i)
					sec = sec <10 ? '0'+sec:sec
				}
			}
		} else {
		 	sec = Math.floor(x)
		 	sec = sec <10 ? '0'+sec:sec
		 }
	} 
	// @ts-ignore
  get_sec(currentTime, sec)
  
	// change currentTime DOM
	// @ts-ignore
  currTime.innerHTML = min + ':' + sec
  
	// define minutes duration
	let min_d = (isNaN(duration) === true)? '0':
    Math.floor(duration / 60);
  
	 // @ts-ignore
	 min_d = min_d <10 ? '0'+min_d:min_d
	 function get_sec_d (x) {
		if(Math.floor(x) >= 60){
			
			for (var i = 1; i<=60; i++){
				if(Math.floor(x)>=(60*i) && Math.floor(x)<(60*(i+1))) {
					sec_d = Math.floor(x) - (60*i)
					sec_d = sec_d <10 ? '0'+sec_d:sec_d
				}
			}
		}else{
		 	sec_d = (isNaN(duration) === true)? '0':
		 	Math.floor(x)
    
		 	// @ts-ignore
      sec_d = sec_d < 10 ? '0' + sec_d : sec_d
      
		 }
	} 
	// define seconds duration
  get_sec_d(duration)
  
	// change duration DOM
	// @ts-ignore
  durTime.innerHTML = min_d + ':' + sec_d
  
};
// Event listeners
// @ts-ignore
playBtn.addEventListener('click', () => {

  // @ts-ignore
  const isPlaying = musicContainer.classList.contains('play')

  if (isPlaying) {
    pauseSong();
  } else {
    playSong();
  }
});

// Change song
// @ts-ignore
prevBtn.addEventListener('click', prevSong)

// @ts-ignore
nextBtn.addEventListener('click', nextSong)

// Time/song update
// @ts-ignore
audio.addEventListener('timeupdate', updateProgress)

// Click on progress bar
// @ts-ignore
progressContainer.addEventListener('click', setProgress)

// Song ends
// @ts-ignore
audio.addEventListener('ended', nextSong)

// Time of song
// @ts-ignore
audio.addEventListener('timeupdate', DurTime)


