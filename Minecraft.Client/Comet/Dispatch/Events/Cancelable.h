struct Cancelable
{
    bool isCanceled() const
    {
        return canceled;
    }
    void cancel()
    {
        canceled = true;
    }

private:
    bool canceled = false;
};