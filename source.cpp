#include <dali-toolkit/dali-toolkit.h>
#include <dali-toolkit/devel-api/controls/text-controls/text-field-devel.h>
#include <dali-toolkit/devel-api/controls/text-controls/text-editor-devel.h>
#include <dali-toolkit/devel-api/visuals/visual-properties-devel.h>
#include <dali/integration-api/events/touch-event-integ.h>
#include <dali/integration-api/events/wheel-event-integ.h>

using namespace Dali;
using namespace Dali::Toolkit;

class SimpleApp : public ConnectionTracker
{
public:
  SimpleApp(Application& application)
  : mApplication(application)
  {
    mApplication.InitSignal().Connect(this, &SimpleApp::Create);
  }

  void Create(Application& application)
  {
    Window window = application.GetWindow();

    mImageView = ImageView::New();
    mImageView.SetProperty(Actor::Property::PARENT_ORIGIN, ParentOrigin::TOP_CENTER);
    mImageView.SetProperty(Actor::Property::ANCHOR_POINT, AnchorPoint::TOP_CENTER);
    mImageView.SetProperty(Actor::Property::POSITION, Vector3(0.f, 0.0f, 0.f));
    mImageView.SetProperty(Actor::Property::SIZE, Vector2(100.0f, 300.0f));
    mImageView.SetBackgroundColor(Vector4(0.3f, 0.3f, 0.3f, 1.0f));

    mImageView2 = ImageView::New();
    mImageView2.SetProperty(Actor::Property::PARENT_ORIGIN, ParentOrigin::TOP_CENTER);
    mImageView2.SetProperty(Actor::Property::ANCHOR_POINT, AnchorPoint::TOP_CENTER);
    mImageView2.SetProperty(Actor::Property::POSITION, Vector3(0.f, 350.0f, 0.f));
    mImageView2.SetProperty(Actor::Property::SIZE, Vector2(100.0f, 300.0f));
    mImageView2.SetBackgroundColor(Vector4(0.7f, 0.7f, 0.7f, 1.0f));


    Property::Map imageMap;
    imageMap[ Toolkit::Visual::Property::TYPE ] = Toolkit::Visual::IMAGE;
    imageMap[ ImageVisual::Property::URL ] = "img.png";
    imageMap[ ImageVisual::Property::FITTING_MODE ] = FittingMode::FIT_WIDTH;
    mImageView.SetProperty(ImageView::Property::IMAGE, imageMap);

    Property::Map imageMap2;
    imageMap2[ Toolkit::Visual::Property::TYPE ] = Toolkit::Visual::IMAGE;
    imageMap2[ ImageVisual::Property::URL ] = "img.png";
    imageMap2[ DevelVisual::Property::VISUAL_FITTING_MODE ] = Toolkit::DevelVisual::FIT_WIDTH;
    mImageView2.SetProperty(ImageView::Property::IMAGE, imageMap2);


    window.Add(mImageView);
    window.Add(mImageView2);
  }

private:
  Application& mApplication;
  ImageView mImageView;
  ImageView mImageView2;
};

int DALI_EXPORT_API main(int argc, char** argv)
{
  Application application = Application::New(&argc, &argv);
  SimpleApp test(application);
  application.MainLoop();

  return 0;
}

