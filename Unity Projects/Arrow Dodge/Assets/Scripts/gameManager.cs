using UnityEngine;
using TMPro;
using UnityEngine.UIElements;
using UnityEngine.SocialPlatforms.Impl;
using UnityEngine.SceneManagement;

public class gameManager : MonoBehaviour
{
    public GameObject OverScreen,PauseScreen;
    bool isPaused = false;
    public TextMeshProUGUI ScoreText;
    public int Score;

    public AudioSource source;

    void Start()
    {
        source = GetComponent<AudioSource>();
    }


    private void Update()
    {
        if (isPaused) return;

        Score++;
        ScoreText.text = "Score : " + Score;
    }

    public void GameOver()
    {
        OverScreen.SetActive(true);
        source.Play();
        Time.timeScale = 0f;
    }

    public void RestartGame()
    {
        Time.timeScale = 1f;
        SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex);
    }

    public void ExitGame()
    {
        Application.Quit();
    }

    public void PauseNResume()
    {
        if(isPaused)
        {
            Time.timeScale = 1;
            PauseScreen.SetActive(false);
        }
        else
        {
            Time.timeScale = 0f;
            PauseScreen.SetActive(true);
        }

        isPaused = !isPaused;
    }
}
