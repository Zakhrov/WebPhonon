Name: WebPhonon
Version: 2.0
Release:	7%{?dist}
Summary: Media Player	
Group:	 Multimedia
License: GPL-2.0+
URL:	https://github.com/Zakhrov/WebPhonon/	
Source0: %{name}-%{version}.tar.gz
#Source1: WebPhonon-1.7.tar.gz
Prefix: %{_prefix}
BuildRoot:	%{_tmppath}/%{name}-%{version}-%{release}-root-%(%{__id_u} -n)

BuildRequires: cmake, libqt4-sql-mysql, libqt4-devel, libQtWebKit4, phonon-devel, libkde4-devel, update-desktop-files
#Requires: libqt4-sql-mysql, libQtWebKit4, libphonon4, libkde4

%kde4_runtime_requires

%description
A simple Phonon based Media player written in Qt

%prep
%setup -q

%build
cmake -DCMAKE_INSTALL_PREFIX=%{_prefix} -DCMAKE_SKIP_RPATH=ON

make %{?_smp_mflags}

%install
rm -rf %{buildroot}
make install  DESTDIR=%{buildroot}

%suse_update_desktop_file -r WebPhonon AudioVideo Video Player


%clean
rm -rf %{buildroot}

%if 0%{?suse_version} >= 1140

%post
%desktop_database_post
%endif

%if 0%{?suse_version} >= 1140
%postun
%desktop_database_postun
%endif


%files
%defattr(-,root,root,-)
%{_bindir}/WebPhonon
%{_datadir}/applications/kde4/WebPhonon.desktop
%{_datadir}/icons/hicolor/*
%{_datadir}/*
%{_datadir}/kde4/services/ServiceMenus/PlayWithWebPhonon.desktop
#/usr/bin/WebPhonon
#/usr/share/applications/kde4/WebPhonon.desktop
#/usr/share/icons/hicolor/16x16/apps/WebPhonon.png
#/usr/share/icons/hicolor/16x16/apps
#/usr/share/icons/hicolor/16x16
#/usr/share/icons/hicolor/32x32/apps/WebPhonon.png
#/usr/share/icons/hicolor/32x32/apps
#/usr/share/icons/hicolor/32x32
#/usr/share/icons/hicolor/48x48/apps/WebPhonon.png
#/usr/share/icons/hicolor/48x48/apps
#/usr/share/icons/hicolor/48x48
#/usr/share/icons/hicolor/64x64/apps/WebPhonon.png
#/usr/share/icons/hicolor/64x64/apps
#/usr/share/icons/hicolor/64x64
#/usr/share/icons/hicolor/128x128/apps/WebPhonon.png
#/usr/share/icons/hicolor/128x128/apps
#/usr/share/icons/hicolor/128x128
#/usr/share/icons/hicolor/256x256/apps/WebPhonon.png
#/usr/share/icons/hicolor/256x256/apps
#/usr/share/icons/hicolor/256x256
#/usr/share/icons/hicolor/512x512/apps/WebPhonon.png
#/usr/share/icons/hicolor/512x512/apps
#/usr/share/icons/hicolor/512x512
#/usr/share/WebPhonon/splash/WebPhonon-Master-text2.png
#/usr/share/kde4/services/ServiceMenus/PlayWithWebPhonon.desktop


%changelog 
