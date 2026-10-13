"""specs_f15b001.py - fresh slice 15 batch 1 (see src/f15b001.cpp)."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, hook


def _o(n):
    def g(c):
        clear_hooks(c)
        return [rnd(c, n)]
    return g


def _none(c):
    clear_hooks(c)
    return []


def _ptr18(c):
    clear_hooks(c)
    me = rnd(c, 0x40)
    c.emu.w32(me + 0x18, rnd(c, 0x20))
    return [me]


def _bones(c):
    clear_hooks(c)
    me = rnd(c, 0x60)
    c.emu.w8(me + 0x3f, c.rng.choice([0, 0, 1, 0x80, c.rng.getrandbits(8)]))
    return [me]


def _lod(c):
    clear_hooks(c)
    c.emu.w32(0x70039c, rnd(c, 0x100))
    return []


def _setb(c):
    clear_hooks(c)
    return [rnd(c, 0x100), c.rng.getrandbits(32)]


def _fwd(c):
    seq = Seq(c)
    clear_hooks(c)
    hook(c, seq, 0x63fea0, 1, ret=c.rng.getrandbits(32))
    return [rnd(c, 0x40), c.rng.getrandbits(32)]


def _638670(c):
    seq = Seq(c)
    clear_hooks(c)
    hook(c, seq, 0x638610, 0, ret=c.rng.getrandbits(32))
    return [rnd(c, 0x40)]


def _push(c):
    seq = Seq(c)
    clear_hooks(c)
    t = rnd(c, 0x28)
    hook(c, seq, 0x557930, 0, ret=t)
    me = rnd(c, 0x20)
    c.emu.w8(me + 0xc, c.rng.choice([0, 0, 1, 0x40, c.rng.getrandbits(8)]))
    return [me, c.rng.getrandbits(32)]


def _view(c):
    seq = Seq(c)
    clear_hooks(c)
    v = obj(c, 0x20, {0x28: stub(c, seq, 2, ret=c.rng.getrandbits(32))})
    me = rnd(c, 0x100)
    c.emu.w32(me + 0xbd, v)
    return [me, c.rng.getrandbits(32)]


N = 'f15b001'
S(0x638cb0, 'REFTAB::Size', 'thiscall', None, ret='eax', gen=_o(0x40), note=N)
S(0x635330, 'ZEventBase::Remove', 'thiscall', None, ret=None, gen=_o(0x10), note=N)
S(0x6053b0, 'OpaqueString_t::getTypeName', 'cdecl', None, ret='eax', gen=_none, note=N)
S(0x607cf0, 'ZPrimControlBase::GetSizeOfLightSpotSquare', 'thiscall', None, ret='eax', gen=_o(0x10), note=N)
S(0x614ef0, 'ZDrawArray<ZGeomDrawEntryGC>::GetNrEntriesPerBlock', 'thiscall', None, ret='eax', gen=_o(0x10), note=N)
S(0x64b130, 'ZDrawArray<ZCameraViewEntry>::EntrySize', 'thiscall', None, ret='eax', gen=_o(0x10), note=N)
S(0x60d830, 'ZRenderGC::EnableFog (folded getter +0x118a)', 'thiscall', None, ret='eax', gen=_o(0x1200), note=N)
S(0x659c30, 'FUN_659c30 (forwarder to ZDrawBase::RoomCreate)', 'thiscall', None, ret='eax', gen=_fwd, note=N + '; 0x63fea0 hooked')
S(0x60ed70, 'ZRender::LOD', 'cdecl', None, ret='eax', gen=_lod, note=N)
S(0x651030, 'ZRender::SetSurroundGaming', 'thiscall', None, ret=None, gen=_setb, note=N)
S(0x651170, 'ZRender::SetWideScreen', 'thiscall', None, ret=None, gen=_setb, note=N)
S(0x658d30, 'ZGeomDrawEntry::Bones', 'thiscall', None, ret='eax', gen=_bones, note=N)
S(0x604370, 'ScriptEvent_t::getEventData', 'thiscall', None, ret='eax', gen=_ptr18, note=N)
S(0x638670, 'FUN_638670 (size + count*4 + 4)', 'thiscall', None, ret='eax', gen=_638670, note=N + '; 0x638610 hooked')
S(0x550c30, 'CFFScriptInterfaceDll::PushScene', 'thiscall', None, ret=None, gen=_push, note=N + '; 0x557930 hooked')
S(0x64f9b0, 'ZRender::CreateView', 'thiscall', None, ret='eax', gen=_view, note=N)
