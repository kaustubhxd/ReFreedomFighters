"""specs_u69_79.py - area 69, group 79 (slice 8): six open residue-8 functions.
GUESS stubs: 0x630000 and 0x62f390 (cdecl, one arg), 0x4de7a0 (thiscall, no args), 0x4df330 (thiscall, four args, ret 0x10).
0x427140 is a naked forwarder (ECX vtable, jmp slot 0x13c, stack untouched); slot 0x13c is a fake callee with one stack arg, ret 4. 0x608e00 executes CPUID on both sides (host-dependent; the value is the emulator's)."""
import struct
from pilot import S, F
from ckit import rnd, rvt


def _f32(x):
    return struct.unpack('<f', struct.pack('<f', x))[0]


def _dispatch(c):
    r = c.rng
    obj = rnd(c, 0x20)
    c.emu.w32(obj + 0xc, r.choice([0, 1]))
    return [obj, r.choice(list(range(0x0c, 0x30)) + [0xffffffff, 0x1c])]


def _walk(c):
    e = c.emu
    r = c.rng
    obj = rnd(c, 0x40)
    Y = rnd(c, 0x40) if r.random() < 0.9 else 0
    e.w32(obj + 0x1c, Y)
    e.w32(obj + 0x20, r.choice([0, 1]))
    e.w32(obj + 0x24, r.choice([1, 2]))
    if Y:
        e.w32(Y + 0x18, r.choice([0, 5, 0xffffffff, 0x80000000]))
        e.w32(Y + 8, r.getrandbits(32))
    e.hook(0x630000, lambda e, res: (e.calllog.append(('t630000', int(e.arg32(0) == Y))), e.ret(argbytes=0)))
    e.hook(0x62f390, lambda e, res: (e.calllog.append(('t62f390', int(e.arg32(0) == Y))), e.ret(argbytes=0)))
    return [obj]


def _tail(c):
    e = c.emu
    obj = rnd(c, 0x10)
    word = c.rng.getrandbits(32)
    # slot 0x13c: fake callee with one stack argument, popped by the callee (ret 4). It logs whether ECX is the
    # object and whether the stack argument came through unchanged (booleans only, no pointers)
    vt = rvt(e, 'tailobj', {0x13c: (1, lambda e, ecx, args: (0x77, None, ('vt13c', int(ecx == obj), int(args[0] == word))), 4)}, nslots=0x140 // 4)
    e.w32(obj, vt)
    return [obj, word]


def _cpuid(c):
    return []


def _scale(c):
    r = c.rng
    n = r.randrange(0, 6)
    arr = rnd(c, 4 * (n + 4))
    vals = [F(_f32(r.uniform(-50.0, 50.0))) for _ in range(n + 2)]
    for i, v in enumerate(vals):
        e = c.emu
        e.wbytes(arr + 4 * i, struct.pack('<f', v.v if hasattr(v, 'v') else float(v)))
    return [arr, n]


def _call(c):
    e = c.emu
    r = c.rng
    obj = rnd(c, 0x40)
    e.hook(0x4de7a0, lambda e, res: (e.calllog.append(('t4de7a0',)), e.ret(argbytes=0)))
    e.hook(0x4df330, lambda e, res: (e.calllog.append(('t4df330', int(e.arg32(0) == obj + 0x18), e.arg32(1), e.arg32(2), e.arg32(3))), e.ret(eax=0x21, argbytes=0x10)))
    return [obj, r.getrandbits(16), r.getrandbits(16), r.getrandbits(16)]


S(0x62d5c0, 'dispatch62d5c0 (cdecl, two args)', 'cdecl', None, ret='eax', gen=_dispatch, note='u69 group 79')
S(0x62f140, 'walk62f140 (stdcall, one arg, ret 4)', 'stdcall', None, ret='eax', gen=_walk, note='u69 group 79; GUESS stubs 0x630000, 0x62f390')
S(0x427140, 'tail427140 (naked jmp forwarder, thiscall with one stack arg)', 'thiscall', None, ret='eax', gen=_tail, note='u69 group 79; forwarder confirmed from exe bytes; slot 0x13c callee is a fake (GUESS)')
S(0x608e00, 'cpuidSse608e00 (cdecl, no args)', 'cdecl', None, ret='eax', gen=_cpuid, note='u69 group 79; host-dependent: executes CPUID on both sides')
S(0x40fe00, 'scale40fe00 (cdecl, two args)', 'cdecl', None, ret=None, gen=_scale, note='u69 group 79; doubles with single-precision stores')
S(0x45b080, 'call45b080 (thiscall, three args, ret 0xc)', 'thiscall', None, ret=None, gen=_call, note='u69 group 79; GUESS stubs 0x4de7a0, 0x4df330')
