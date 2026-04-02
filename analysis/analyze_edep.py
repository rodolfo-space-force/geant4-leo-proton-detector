import sys
    out_dir = csv_path.parent / "analysis_outputs"
    out_dir.mkdir(exist_ok=True)

    # Histogram of deposited energy
    plt.figure(figsize=(8, 5))
    plt.hist(df["edep_MeV"], bins=100)
    plt.xlabel("Deposited energy (MeV)")
    plt.ylabel("Counts")
    plt.title("Energy deposition spectrum")
    plt.tight_layout()
    plt.savefig(out_dir / "hist_edep.png", dpi=200)
    plt.close()

    # Scatter: incident energy vs deposited energy
    plt.figure(figsize=(8, 5))
    plt.scatter(df["incident_energy_MeV"], df["edep_MeV"], s=5, alpha=0.4)
    plt.xlabel("Incident proton energy (MeV)")
    plt.ylabel("Deposited energy (MeV)")
    plt.title("Incident energy vs deposited energy")
    plt.tight_layout()
    plt.savefig(out_dir / "scatter_incident_vs_edep.png", dpi=200)
    plt.close()

    # Binned response curve
    bins = np.linspace(df["incident_energy_MeV"].min(), df["incident_energy_MeV"].max(), 15)
    df["energy_bin"] = pd.cut(df["incident_energy_MeV"], bins=bins, include_lowest=True)
    grouped = df.groupby("energy_bin", observed=False).agg(
        incident_mean=("incident_energy_MeV", "mean"),
        edep_mean=("edep_MeV", "mean"),
        edep_std=("edep_MeV", "std"),
        counts=("edep_MeV", "count"),
    ).dropna()

    plt.figure(figsize=(8, 5))
    plt.errorbar(
        grouped["incident_mean"],
        grouped["edep_mean"],
        yerr=grouped["edep_std"].fillna(0),
        fmt="o",
        capsize=4,
    )
    plt.xlabel("Mean incident proton energy (MeV)")
    plt.ylabel("Mean deposited energy (MeV)")
    plt.title("Detector response curve")
    plt.tight_layout()
    plt.savefig(out_dir / "response_curve.png", dpi=200)
    plt.close()

    grouped.to_csv(out_dir / "response_curve.csv", index=False)
    print(f"\nSaved plots and tables to: {out_dir}")


if __name__ == "__main__":
    main()